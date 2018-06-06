#include "lua_leveldb.h"
#include <cassert>
#include <stdio.h> 

LuaLeveldb::LuaLeveldb(const char *path) {
   //    printf("Open db start \n");
  leveldb::Options options;
  options.create_if_missing = true;
  options.error_if_exists = false;
  options.write_buffer_size = 100 * 1024 * 1024;
  //options.block_cache = cache_;
  options.compression = leveldb::kNoCompression;
  //     printf("Open db start 2\n");
  leveldb::Status status = leveldb::DB::Open(options, path, &db);
/*  
if(status.ok()==true){
     printf("Open db ok\n");
  }else{
     printf("Open db false\n");
  }
*/
  assert(status.ok());

}

LuaLeveldb::~LuaLeveldb() {
  //printf("delete db\n");
  if(db) {
       //printf("real delete db\n");
     delete db;
  }
}
void LuaLeveldb::get(const char *key, RecordResponse *record) {
  std::string value;
  leveldb::Status s = db->Get(leveldb::ReadOptions(), key, &value);
  if(s.ok()) {
    record->code = Success;
    record->len= value.size();
    return;
  }
  record->code = RecordNotFound;
}

void LuaLeveldb::read_data(const char *key, const char *data) {
  std::string value;
  leveldb::Status s = db->Get(leveldb::ReadOptions(), key, &value);
  if(s.ok()) {
    memcpy((void *)data, value.c_str(), value.size());
    return;
  }
  data = NULL;
}


int LuaLeveldb::set(const char *key, const char *value) {
  leveldb::WriteOptions write_opts;
  write_opts.sync = true;
  leveldb::Status s = db->Put(write_opts, key, value);
  if(s.ok()) return Success;
  return Error;
}

int LuaLeveldb::del(const char *key) {
  leveldb::WriteOptions options;
  options.sync = true;
  leveldb::Status s = db->Delete(options, key);
  if (s.IsNotFound()) {
    return RecordNotFound;
  }
  if(s.ok()) return Success;
  return Error;
}

int LuaLeveldb::insert(const char *key, const char *value) {
  leveldb::Status s;
  std::string record;

  s = db->Get(leveldb::ReadOptions(), key, &record);
  if(s.ok()) {
    return RecordExists;
  }

  leveldb::WriteOptions options;
  options.sync = true;
  s = db->Put(options, key, value);
  if(s.ok()) return Success;
  return Error;
}

int LuaLeveldb::update(const char *key, const char *value) {
  leveldb::Status s;
  std::string record;

  s = db->Get(leveldb::ReadOptions(), key, &record);
  if(s.IsNotFound()) {
    return RecordNotFound;
  }

  leveldb::WriteOptions options;
  options.sync = true;
  s = db->Put(options, key, value);
  if(s.ok()) return Success;
  return Error;
}

