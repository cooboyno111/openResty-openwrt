include $(TOPDIR)/rules.mk

PKG_NAME:=leveldb
PKG_VERSION:=1.20
PKG_RELEASE:=1

PKG_SOURCE:=v$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://github.com/google/leveldb/archive/
PKG_MD5SUM:=298b5bddf12c675d6345784261302252
PKG_BUILD_PARALLEL:=1
PKG_USE_MIPS16:=0
include $(INCLUDE_DIR)/package.mk

define Package/leveldb
  DEPENDS:=+libstdcpp
  SECTION:=Libaries
  CATEGORY:=openResty
  TITLE:=A fast and lightweight key/value database library
  URL:=https://code.google.com/p/leveldb/
endef

define Package/leveldb/description
A fast and lightweight key/value database library
endef

define Build/Configure
  $(call Build/Configure/Default)
endef

define Build/Compile
  $(call Build/Compile/Default)
endef

define Package/leveldb/install
	$(INSTALL_DIR) $(1)/usr/lib
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/out-shared/libleveldb.so.1.20 $(1)/usr/lib/
	ln -s /usr/lib/libleveldb.so.1.20 $(1)/usr/lib/libleveldb.so.1
	ln -s /usr/lib/libleveldb.so.1.20 $(1)/usr/lib/libleveldb.so
endef

$(eval $(call BuildPackage,leveldb))
