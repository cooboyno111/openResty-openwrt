include $(TOPDIR)/rules.mk

PKG_NAME:=snappy
PKG_VERSION:=1.1.3
PKG_RELEASE:=1

PKG_SOURCE:=snappy-$(PKG_VERSION).tar.gz
PKG_SOURCE_URL:=https://github.com/google/snappy/releases/download/$(PKG_VERSION)/
PKG_MD5SUM:=7358c82f133dc77798e4c2062a749b73

PKG_BUILD_PARALLEL:=1

include $(INCLUDE_DIR)/package.mk

define Package/snappy
  DEPENDS:=+libstdcpp
  SECTION:=Libaries
  CATEGORY:=openResty
  TITLE:=A fast compressor/decompressor library
  URL:=https://google.github.io/snappy/
endef

define Package/snappy/description
A fast compressor/decompressor library
endef

define Build/Configure
  $(call Build/Configure/Default)
endef

define Build/Compile
  $(call Build/Compile/Default)
endef

define Package/snappy/install
  $(MAKE) $(PKG_JOBS) -C $(PKG_BUILD_DIR) DESTDIR="$(1)" install
endef

$(eval $(call BuildPackage,snappy))
