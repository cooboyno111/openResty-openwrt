ffi = require 'ffi'

libpath = "/usr/lib/lua/liblualeveldb.so"

ffi.cdef[[
  typedef struct RecordResponse_s {
    int code;
    int len;
  } RecordResponse;
  typedef struct LuaLeveldb LuaLeveldb;
  LuaLeveldb *new_leveldb(const char *path);
  void get(LuaLeveldb *db, const char *key, RecordResponse *record);
  int set(LuaLeveldb *db, const char *key, const char *value);
  int del(LuaLeveldb *db, const char *key);
  int insert(LuaLeveldb *db, const char *key, const char *value);
  int update(LuaLeveldb *db, const char *key, const char *value);
  void read_data(LuaLeveldb *db, const char *key, const char *value);
  void LuaLeveldb_gc(LuaLeveldb *this);
]]

local _M = {
  _VERSION = '0.0.1'
}

local commands = {
  "set", "del", "insert", "update"
}

local mt = { __index = _M }
local leveldb

function _M.get(self, key)
  local record = ffi.new("RecordResponse", {1})
  leveldb.get(self.super, key, record)
  if record.code == 0 then
    local value = ffi.new("char[?]", record.len + 1);
    leveldb.read_data(self.super, key, value)
    if value ~= ffi.NULL then
      return ffi.string(value, record.len)
    else
      return nil
    end
  else
    return nil
  end
end

for k, v in ipairs(commands) do
  _M[v] = function(self, ...)
    return leveldb[v](self.super, ...)
  end
end

function load_leveldb()
  if leveldb ~= nil then
    return leveldb
  else
    leveldb = ffi.load(libpath)
    return leveldb
  end
end

function _M.new(self, path)
  if not leveldb then
    load_leveldb()
  end
  local self = {super=leveldb.new_leveldb(path)}
  ffi.gc(self.super, leveldb.LuaLeveldb_gc)
  return setmetatable(self, mt)
end

return _M
