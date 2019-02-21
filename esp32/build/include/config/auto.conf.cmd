deps_config := \
	/home/maxx/develop/esp32/esp-idf/components/app_trace/Kconfig \
	/home/maxx/develop/esp32/esp-idf/components/aws_iot/Kconfig \
	/home/maxx/develop/esp32/esp-idf/components/bt/Kconfig \
	/home/maxx/develop/esp32/esp-idf/components/driver/Kconfig \
	/home/maxx/develop/esp32/esp-idf/components/esp32/Kconfig \
	/home/maxx/develop/esp32/esp-idf/components/esp_adc_cal/Kconfig \
	/home/maxx/develop/esp32/esp-idf/components/esp_http_client/Kconfig \
	/home/maxx/develop/esp32/esp-idf/components/ethernet/Kconfig \
	/home/maxx/develop/esp32/esp-idf/components/fatfs/Kconfig \
	/home/maxx/develop/esp32/esp-idf/components/freertos/Kconfig \
	/home/maxx/develop/esp32/esp-idf/components/heap/Kconfig \
	/home/maxx/develop/esp32/esp-idf/components/libsodium/Kconfig \
	/home/maxx/develop/esp32/esp-idf/components/log/Kconfig \
	/home/maxx/develop/esp32/esp-idf/components/lwip/Kconfig \
	/home/maxx/develop/esp32/esp-idf/components/mbedtls/Kconfig \
	/home/maxx/develop/esp32/esp-idf/components/openssl/Kconfig \
	/home/maxx/develop/esp32/esp-idf/components/pthread/Kconfig \
	/home/maxx/develop/esp32/esp-idf/components/spi_flash/Kconfig \
	/home/maxx/develop/esp32/esp-idf/components/spiffs/Kconfig \
	/home/maxx/develop/esp32/esp-idf/components/tcpip_adapter/Kconfig \
	/home/maxx/develop/esp32/esp-idf/components/vfs/Kconfig \
	/home/maxx/develop/esp32/esp-idf/components/wear_levelling/Kconfig \
	/home/maxx/develop/esp32/esp-idf/components/bootloader/Kconfig.projbuild \
	/home/maxx/develop/esp32/esp-idf/components/esptool_py/Kconfig.projbuild \
	/home/maxx/develop/esp32/esp-idf/components/partition_table/Kconfig.projbuild \
	/home/maxx/develop/esp32/esp-idf/Kconfig

include/config/auto.conf: \
	$(deps_config)

ifneq "$(IDF_CMAKE)" "n"
include/config/auto.conf: FORCE
endif

$(deps_config): ;
