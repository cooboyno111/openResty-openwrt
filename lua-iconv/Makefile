include $(TOPDIR)/rules.mk

PKG_NAME:=lua-iconv
PKG_VERSION:=0.7
PKG_RELEASE:=1

PKG_SOURCE:=$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://github.com/cooboyno111/lua-iconv/archive/
PKG_MD5SUM:=a2a00654fcaeb8373d401628e76a93f3
PKG_BUILD_PARALLEL:=1

include $(INCLUDE_DIR)/package.mk

define Package/lua-iconv
  DEPENDS:=+libiconv-full
  SECTION:=Libaries
  CATEGORY:=openResty
  TITLE:=lua-iconv
  URL:=https://github.com/ittner/lua-iconv
endef

define Package/lua-iconv/description
lua-iconv
endef

define Build/Configure
  $(call Build/Configure/Default)
endef

define Build/Compile
  $(call Build/Compile/Default)
endef

define Package/lua-iconv/install
	$(INSTALL_DIR) $(1)/usr/lib/lua
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/iconv.so $(1)/usr/lib/lua/iconv.so
endef

$(eval $(call BuildPackage,lua-iconv))
