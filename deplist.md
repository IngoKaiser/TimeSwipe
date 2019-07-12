# Dependencies and associated licences for the project:

## third party dependencies for the firmware:

- GNU Arm Embedded Toolchain  <br />
    Pre-built GNU toolchain for Arm Cortex-M and Cortex-R processors  https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm  <br />
    dir: outside the project folder <br />
    status: original <br />
    license: These toolchains are based on Free Software Foundation's (FSF) GNU Open source tools and newlib.

- startup_ARMCM4.S: <br />
    assembler startup code https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm <br />
    dir: /prj_templ/Custom <br />
    status: changed/tuned <br />
    license: ? (Please, see license conditions inside the file)
    
- gcc.ld, gcc_RAM.ld: <br />
    linker scripts https://developer.arm.com/tools-and-software/open-source-software/developer-tools/gnu-toolchain/gnu-rm <br />
    dir: /prj_templ/Custom <br />
    status: changed/tuned <br />
    license: ? (No license description)
    
- CMSIS library: <br />
    CortexMx control library https://start.atmel.com, https://developer.arm.com/tools-and-software/embedded/cmsis <br />
    dir: /prj_templ/CMSIS <br />
    status: original <br />
    license: Apache-2.0 www.apache.org/licenses/LICENSE-2.0
    
- SAME54's header files from manufactor (Atmel/Microchip) <br />
    chip's perephireals description https://start.atmel.com <br /> 
    dir: /prj_templ/include <br />
    status: original <br />
    license: Apache-2.0 www.apache.org/licenses/LICENSE-2.0
    
 - Adafruit_NeoPixel <br />
    an Arduino library used for control of LEDs https://github.com/adafruit/Adafruit_NeoPixel <br />
    dir: /Adafruit_NeoPixel <br />
    status: changed/tuned <br />
    license: GNU LESSER GENERAL PUBLIC LICENSE
 
 -  nlohmann/json <br />
    JSON for Modern C++ https://nlohmann.github.io/json/ <br />
    dir: outside the project folder <br />
    status: original <br />
    license: MIT License
    
    ## third party dependencies for the rPIs client software:
    
 -  bcm2835 library  <br />
    C library for Broadcom BCM 2835 as used in Raspberry Pi  https://www.airspayce.com/mikem/bcm2835/ <br />
    dir: /BCMsrc <br />
    status: changed/tuned <br />
    license: Open Source Licensing GPL V2 https://www.gnu.org/licenses/gpl-2.0.html
    