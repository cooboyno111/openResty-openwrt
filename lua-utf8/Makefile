include $(TOPDIR)/rules.mk

PKG_NAME:=luautf8
PKG_VERSION:=0.13
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://github.com/cooboyno111/luautf8/archive/
PKG_MD5SUM:=443be7116cb1e4332cf4c5501d67e88a
PKG_BUILD_PARALLEL:=1

include $(INCLUDE_DIR)/package.mk

define Package/luautf8
  SECTION:=Libaries
  CATEGORY:=openResty
  TITLE:=lua-utf8
  URL:=https://github.com/starwing/luautf8
endef

define Package/luautf8/description
lua-utf8
endef

define Build/Configure
  $(call Build/Configure/Default)
endef

define Build/Compile
  $(call Build/Compile/Default)
endef

define Package/luautf8/install
	$(INSTALL_DIR) $(1)/usr/lib/lua
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/lua-utf8.so $(1)/usr/lib/lua/lua-utf8.so
endef

$(eval $(call BuildPackage,luautf8))
