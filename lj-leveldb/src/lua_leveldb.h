#include "leveldb/db.h"
#include "leveldb/cache.h"
#include <iostream>
using namespace std;

extern "C" {
  enum responseCode {
    Success = 0,
    Error,
    RecordNotFound,
    RecordExists
  };

  typedef struct RecordResponse_s {
    int code;
    int len;
  } RecordResponse;
}

class LuaLeveldb {
  public:
    LuaLeveldb(const char *path);
    ~LuaLeveldb();
    void close();
    void get(const char *key, RecordResponse *record);
    int set(const char *key, const char *value);
    int del(const char *key);
    int insert(const char *key, const char *value);
    int update(const char *key, const char *value);
    void read_data(const char *key, const char *data);
  private:
    leveldb::DB* db;
    //leveldb::Cache* cache_;
    uint32_t writeBufferSizeMb_;
    uint32_t blockCacheSizeMb_;
};

extern "C" {
  LuaLeveldb *new_leveldb(const char *path) {
    return new LuaLeveldb(path);
  }
  void close(LuaLeveldb *_this){
   _this->close();
  }
  void get(LuaLeveldb *_this, const char *key, RecordResponse *record) {
    _this->get(key, record);
  }

  int set(LuaLeveldb *_this, const char *key, const char *value) {
    return _this->set(key, value);
  }

  int del(LuaLeveldb *_this, const char *key) {
    return _this->del(key);
  }

  int insert(LuaLeveldb *_this, const char *key, const char *value) {
    return _this->insert(key, value);
  }

  int update(LuaLeveldb *_this, const char *key, const char *value) {
    return _this->update(key, value);
  }

  void read_data(LuaLeveldb *_this, const char *key, const char *value) {
    return _this->read_data(key, value);
  }

  void LuaLeveldb_gc(LuaLeveldb *_this) {
    delete _this;
  }
}
