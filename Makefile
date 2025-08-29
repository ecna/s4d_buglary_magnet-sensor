# SPDX-FileCopyrightText: © 2022 Uri Shaked <uri@wokwi.com>
# SPDX-License-Identifier: MIT

SOURCES = src/magnet-sensor-chip.c
TARGET  = dist/magnet-sensor-chip.wasm

.PHONY: all
all: $(TARGET) dist/magnet-sensor-chip.json

.PHONY: clean
clean:
		rm -rf dist

dist:
		mkdir -p dist

$(TARGET): dist $(SOURCES) src/wokwi-api.h
	  clang --target=wasm32-unknown-wasi --sysroot /opt/wasi-libc -nostartfiles -Wl,--import-memory -Wl,--export-table -Wl,--no-entry -Werror -o $(TARGET) $(SOURCES)

dist/magnet-sensor-chip.json: dist magnet-sensor-chip.json
	  cp magnet-sensor-chip.json dist

.PHONY: test
test:
	  cd test && arduino-cli compile -e -b arduino:avr:uno magnet
