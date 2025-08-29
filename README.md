# chip-magnet-sensor for S4D minor barglary alarm


The actual source code for the chip lives in [src/main.c](src/magnet-sensor-chip.c), and the pins are described in [magnet-sensor-chip.json](magnet-sensor-chip.json).

## Building

The easiest way to build the project is to open it inside a Visual Studio Code dev container, and then run the `make` command.

## Testing

You can test this project using the [Wokwi extension for VS Code](https://marketplace.visualstudio.com/items?itemName=wokwi.wokwi-vscode). Open the project with Visual Studio Code, press "F1" and select "Wokwi: Start Simulator".

If you want to make changes to the test project firmware, edit [test/magnet/magnet.ino](test/magnet/magnet.ino), and then run `make test` to rebuild the .hex file. You'll need the [arduino-cli](https://arduino.github.io/arduino-cli/latest/installation/), which is already installed in the dev container.

## License

This project is licensed under the MIT license. See the [LICENSE](LICENSE) file for more details.
