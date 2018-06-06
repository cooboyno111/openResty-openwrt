include $(TOPDIR)/rules.mk

PKG_NAME:=lua-leveldb
PKG_VERSION:=0.47
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://github.com/cooboyno111/lua-leveldb/archive/
PKG_MD5SUM:=a24d7440a9cada1e9204d58e0fad9f39
PKG_BUILD_PARALLEL:=1

include $(INCLUDE_DIR)/package.mk

define Package/lua-leveldb
  DEPENDS:=+libstdcpp +leveldb
  SECTION:=Libaries
  CATEGORY:=openResty
  TITLE:=Lua bindings for Google's LevelDB key/store database.
  URL:=https://github.com/marcopompili/lua-leveldb
endef

define Package/lua-leveldb/description
A fast and lightweight key/value database library
endef

define Build/Configure
  $(call Build/Configure/Default)
endef

define Build/Compile
  $(call Build/Compile/Default)
endef

define Package/lua-leveldb/install
	$(INSTALL_DIR) $(1)/usr/lib/lua
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/lualeveldb.so $(1)/usr/lib/lua/lualeveldb.so
endef

$(eval $(call BuildPackage,lua-leveldb))
