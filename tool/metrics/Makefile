C_HEADERS    ?= ~/Projects/c_headers/include/
BTSTACK_ROOT ?= ../..

VPATH=${BTSTACK_ROOT}/src

INCLUDES= \
	-I ${BTSTACK_ROOT}/src \
	-I ${BTSTACK_ROOT}/3rd-party/micro-ecc/ \
	-I ${BTSTACK_ROOT}/3rd-party/md5 \
	-I ${BTSTACK_ROOT}/3rd-party/bluedroid/decoder/include/ \
	-I ${BTSTACK_ROOT}/3rd-party/bluedroid/encoder/include/ \
	-I ${BTSTACK_ROOT}/3rd-party/yxml \
	-I .

SRC_FILES=$(wildcard ${BTSTACK_ROOT}/src/*.c)
SRC_BLE_FILES=$(wildcard ${BTSTACK_ROOT}/src/ble/*.c)
SRC_BLE_GATT_FILES_FILES=$(wildcard ${BTSTACK_ROOT}/src/ble/gatt-service/*.c)
SRC_CLASSIC_FILES=$(wildcard ${BTSTACK_ROOT}/src/classic/*.c)
SRC_3RD_RIJNDAEL=${BTSTACK_ROOT}/3rd-party/rijndael/rijndael.c
SRC_3RD_UECC=${BTSTACK_ROOT}/3rd-party/micro-ecc/uECC.c
SRCS = ${SRC_FILES} ${SRC_BLE_FILES} ${SRC_BLE_GATT_SERVICE_FILES} ${SRC_CLASSIC_FILES} ${SRC_3RD_RIJNDAEL} ${SRC_3RD_UECC}

all: metrics.md metrics.html

metrics.tsv: ${SRCS}
	ccsm --disable-file --disable-global --exclude-std-headers --exclude-file=.h$$ --output-format=tsv --output-metrics=HIS_.* $^ -- -DuECC_NO_DEFAULT_RNG -isystem ${C_HEADERS}/c90 -isystem ${C_HEADERS}/c99 ${INCLUDES} > $@

metrics.md: metrics.tsv metrics-ccsm.py
	./metrics-ccsm.py > metrics.md

metrics.html: metrics.md
	pandoc --from markdown --to html -o metrics.html metrics.md

clean:
	rm -f metrics.tsv metrics.md
