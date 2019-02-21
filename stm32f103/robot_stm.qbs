//Подключаем стандартные библиотеки в стиле QML
//Основные концепции языка:
//Проект (Project), Продукт (Product), Артефакт (Artifact), Модуль (Module), Правило (Rule), Группа(Group), Зависимость (Depends), Тег (Tag).
//Продукт — это аналог pro или vcproj, т. е. одна цель для сборки.
//Проект — это набор ваших продуктов вместе с зависимостями, воспринимаемый системой сборки как одно целое. Один проект — один граф сборки.
//Тег — система классификации файлов. Например «*.cpp» => «cpp»
//Правило — Преобразование файлов проекта, отмеченных определенными тегами. Генерирует другие файлы, называемые Артефактами.
//Как правило, это компиляторы или другие системы сборки.
//Артефакт — файл, над который является выходным для правила (и возможно, входным для други правил). Это обычно «obj», «exe» файлы.
//У многих QML-объектов есть свойство condition, которое отвечает за то, будет собираться он или нет. А если нам необходимо разделить так файлы?
//Для этого их можно объединить в группу (Group)
//Rule умеет срабатывать на каждый файл, попадающий под что-то. Может срабатывать по разу на каждый фаил (например, для вызова компилятора), а может один раз на все (линкер).
//Transformer предназначен для срабатывания только на один фаил, с заранее определенным именем. Например, прошивальщик или какой-нибудь хитрый скрипт.
//флаг multiplex, который говорит о том, что это правило обрабатывает сразу все файлы данного типа скопом.

// We connect standard libraries in style QML
// Basic concepts of the language:
// Project, Product, Artifact, Module, Rule, Group, Depends, Tag.
// The product is an analog of pro or vcproj, that is, one target for the assembly.
// The project is a set of your products together with dependencies, perceived by the build system as one. One project - one assembly graph.
// Tag - file classification system. For example, "* .cpp" => "cpp"
// Rule - Converting project files marked with certain tags. Generates other files called Artifacts.
// Typically, these are compilers or other build systems.
// Artifact is the file over which is the output for the rule (and possibly the input for other rules). These are usually "obj", "exe" files.
// Many QML objects have a condition property, which is responsible for whether it will be assembled or not. And if we need to split the files like this?
// To do this, you can group them into a group (Group)
// Rule is able to work on every file that falls under something. It can trigger once per each file (for example, to call the compiler), but can once on all (linker).
// Transformer is intended for triggering only one file, with a predefined name. For example, the broacher or some cunning script.
// the multiplex flag, which says that this rule processes all files of this type at once.

import qbs
import qbs.FileInfo
import qbs.ModUtils

CppApplication {

    // основной элемент файла - проект.

    //    moduleSearchPaths: "qbs" // Папка для поиска дополнительных модулей, таких как cpp и qt

    // Один проект может состоять из нескольких продуктов - конечных целей сборки.
    // Один проект может состоять из нескольких продуктов - конечных целей сборки.
    // указываем связанные файлы с помощью references. Внимание: это не жестко заданный порядок!
    // Порядок задается с помощью зависимостей, о них позже
    //    references: [
    //           "*.qbs",
    //       ]

    // the main element of the file is the project.

    // moduleSearchPaths: "qbs" // Folder for finding additional modules, such as cpp and qt

    // One project can consist of several products - the final assembly goals.
    // One project can consist of several products - the final assembly goals.
    // specify the related files with references. Attention: this is not a rigidly prescribed order!
    // The order is specified using dependencies, about them later
    // references: [
    // "* .qbs",
    //]


    name: "Robot_stm32"
    // Название выходного файла (без суффикса, он зависит от цели)
    // The name of the output file (without the suffix, it depends on the purpose)
    type: [
        "application",
        "bin",
        "hex",
        // Тип - приложение, т.е. исполняемый файл.
        // Type - application, i.e. executable file.
    ]

    Depends {
        name: "cpp"
        // Этот продукт зависит от компилятора C++
        // This product depends on the C ++ compiler
    }

    consoleApplication: true
    cpp.positionIndependentCode: false
    cpp.executableSuffix: ".elf"

    property string Home: path
    property string SDK: "/home/maxx/develop/STM32/M3"
    property string SPL: SDK + "/SPL"
    property string CMSIS: SDK + "/CMSIS"
    property string INC:  Home+"/Inc"
    property string SRC:  Home+"/Src"
    property string STARTUP: SDK + "/STARTUP"
    property string Config: Home + "/Config"
    property string FreeRTOS: Home + "/FreeRTOS"



    Group {
    name: "FreeRTOS"
	    files: [
		path + "/FreeRTOS/src/*.c",
		path + "/FreeRTOS/include/*.h",
	    ]
	}

    Group {
    name: "Config"
	files: [
	    path + "/config/*.c",
	    path + "/config/*.h",    
        ]
    }
    
    Group {
        name: "SPL"
        files: [
            SPL + "/inc/*.h",
            SPL + "/src/*.c",
            ]
        
    }

    Group {
        name: "CMSIS"
        files: [
            CMSIS + "/inc/*.h",
            CMSIS + "/src/*.c",
            CMSIS + "/Lib/*",
         ]
        excludeFiles: [
            Config + "/system_stm32f1xx.c",
        ]
    }

    Group {
        name: "Inc"
        files: [
             INC + "/*.h",
        ]
    }

    Group {
        name: "Src"
        files: [
            SRC + "/*.c",
            SRC + "/*.cpp",
        ]

    }

    Group {
        name: "STARTUP"
        files: [
            STARTUP + "/startup_stm32f103xe.s",
        ]
    }


    Group {
        // Имя группы
        // A group name
        name: "LD"
        // Список файлов в данном проекте
        // List of files in this project
        files: [
            SDK + "/LD/STM32F103XE_FLASH.ld",
        ]
    }

    // Каталоги с включенными файлами
    // Directories with included files
    cpp.includePaths: [
        Config,
        CMSIS + "/inc",
        SPL + "/inc",
        INC,
        path + "/FreeRTOS/include",
    
    ]

    cpp.defines: [
        "USE_STDPERIPH_DRIVER",
        //"STM32F1xx",

//        "USE_STM32746G_DISCOVERY",
 //       "__weak=__attribute__((weak))",
 //       "__packed=__attribute__((__packed__))",

    ]

    //    --------------------------------------------------------------------
    //    | ARM Core | Command Line Options                       | multilib |
    //    |----------|--------------------------------------------|----------|
    //    |Cortex-M0+| -mthumb -mcpu=cortex-m0plus                | armv6-m  |
    //    |Cortex-M0 | -mthumb -mcpu=cortex-m0                    |          |
    //    |Cortex-M1 | -mthumb -mcpu=cortex-m1                    |          |
    //    |          |--------------------------------------------|          |
    //    |          | -mthumb -march=armv6-m                     |          |
    //    |----------|--------------------------------------------|----------|
    //    |Cortex-M3 | -mthumb -mcpu=cortex-m3                    | armv7-m  |
    //    |          |--------------------------------------------|          |
    //    |          | -mthumb -march=armv7-m                     |          |
    //    |----------|--------------------------------------------|----------|
    //    |Cortex-M4 | -mthumb -mcpu=cortex-m4                    | armv7e-m |
    //    |(No FP)   |--------------------------------------------|          |
    //    |          | -mthumb -march=armv7e-m                    |          |
    //    |----------|--------------------------------------------|----------|
    //    |Cortex-M4 | -mthumb -mcpu=cortex-m4 -mfloat-abi=softfp | armv7e-m |
    //    |(Soft FP) | -mfpu=fpv4-sp-d16                          | /softfp  |
    //    |          |--------------------------------------------|          |
    //    |          | -mthumb -march=armv7e-m -mfloat-abi=softfp |          |
    //    |          | -mfpu=fpv4-sp-d16                          |          |
    //    |----------|--------------------------------------------|----------|
    //    |Cortex-M4 | -mthumb -mcpu=cortex-m4 -mfloat-abi=hard   | armv7e-m |
    //    |(Hard FP) | -mfpu=fpv4-sp-d16                          | /fpu     |
    //    |          |--------------------------------------------|          |
    //    |          | -mthumb -march=armv7e-m -mfloat-abi=hard   |          |
    //    |          | -mfpu=fpv4-sp-d16                          |          |
    //    |----------|--------------------------------------------|----------|
    //    |Cortex-M7 | -mthumb -mcpu=cortex-m7                    | armv7e-m |
    //    |(No FP)   |--------------------------------------------|          |
    //    |          | -mthumb -march=armv7e-m                    |          |
    //    |----------|--------------------------------------------|----------|
    //    |Cortex-M7 | -mthumb -mcpu=cortex-m7 -mfloat-abi=softfp | armv7e-m |
    //    |(Soft FP) | -mfpu=fpv5-sp-d16                          | /softfp  |
    //    |          |--------------------------------------------|          |
    //    |          | -mthumb -march=armv7e-m -mfloat-abi=softfp |          |
    //    |          | -mfpu=fpv5-sp-d16                          |          |
    //    |          |--------------------------------------------|          |
    //    |          | -mthumb -mcpu=cortex-m7 -mfloat-abi=softfp |          |
    //    |          | -mfpu=fpv5-d16                             |          |
    //    |          |--------------------------------------------|          |
    //    |          | -mthumb -march=armv7e-m -mfloat-abi=softfp |          |
    //    |          | -mfpu=fpv5-d16                             |          |
    //    |----------|--------------------------------------------|----------|
    //    |Cortex-M7 | -mthumb -mcpu=cortex-m7 -mfloat-abi=hard   | armv7e-m |
    //    |(Hard FP) | -mfpu=fpv5-sp-d16                          | /fpu     |
    //    |          |--------------------------------------------|          |
    //    |          | -mthumb -march=armv7e-m -mfloat-abi=hard   |          |
    //    |          | -mfpu=fpv5-sp-d16                          |          |
    //    |          |--------------------------------------------|          |
    //    |          | -mthumb -mcpu=cortex-m7 -mfloat-abi=hard   |          |
    //    |          | -mfpu=fpv5-d16                             |          |
    //    |          |--------------------------------------------|          |
    //    |          | -mthumb -march=armv7e-m -mfloat-abi=hard   |          |
    //    |          | -mfpu=fpv5-d16                             |          |
    //    |----------|--------------------------------------------|----------|
    //    |Cortex-R4 | [-mthumb] -march=armv7-r                   | armv7-ar |
    //    |Cortex-R5 |                                            | /thumb   |
    //    |Cortex-R7 |                                            |          |
    //    |(No FP)   |                                            |          |
    //    |----------|--------------------------------------------|----------|
    //    |Cortex-R4 | [-mthumb] -march=armv7-r -mfloat-abi=softfp| armv7-ar |
    //    |Cortex-R5 | -mfpu=vfpv3-d16                            | /thumb   |
    //    |Cortex-R7 |                                            | /softfp  |
    //    |(Soft FP) |                                            |          |
    //    |----------|--------------------------------------------|----------|
    //    |Cortex-R4 | [-mthumb] -march=armv7-r -mfloat-abi=hard  | armv7-ar |
    //    |Cortex-R5 | -mfpu=vfpv3-d16                            | /thumb   |
    //    |Cortex-R7 |                                            | /fpu     |
    //    |(Hard FP) |                                            |          |
    //    |----------|--------------------------------------------|----------|
    //    |Cortex-A* | [-mthumb] -march=armv7-a                   | armv7-ar |
    //    |(No FP)   |                                            | /thumb   |
    //    |----------|--------------------------------------------|----------|
    //    |Cortex-A* | [-mthumb] -march=armv7-a -mfloat-abi=softfp| armv7-ar |
    //    |(Soft FP) | -mfpu=vfpv3-d16                            | /thumb   |
    //    |          |                                            | /softfp  |
    //    |----------|--------------------------------------------|----------|
    //    |Cortex-A* | [-mthumb] -march=armv7-a -mfloat-abi=hard  | armv7-ar |
    //    |(Hard FP) | -mfpu=vfpv3-d16                            | /thumb   |
    //    |          |                                            | /fpu     |
    //    --------------------------------------------------------------------

    cpp.commonCompilerFlags: [
        "-mcpu=cortex-m3",
        "-march=armv7-m",
        "-std=c99",
      //  "-specs=nano.specs",
      //  "-specs=nosys.specs",
        "-mthumb",
    ]

    cpp.driverFlags: [
        "-mcpu=cortex-m3",
        "-march=armv7-m",
        "-std=c99",
        "-mthumb",
        "-Xlinker",
        "--gc-sections",
        "-specs=nosys.specs",
     //   "-specs=nano.specs",

    ]

    cpp.linkerFlags: [
        "--start-group",
        "-T" + SDK + "/LD/STM32F103XE_FLASH.ld",
    ]


    Properties {
        condition: qbs.buildVariant === "debug"
        cpp.debugInformation: true
        cpp.optimization: "none"
    }

    Properties {
        condition: qbs.buildVariant === "release"
        cpp.debugInformation: false
        cpp.optimization: "small"
        // Виды оптимизаций
        // Types of optimizations
        // "none", "fast", "small"
    }

    Properties {
        condition: cpp.debugInformation
        cpp.defines: outer.concat("DEBUG")
    }

    Group {
        // Properties for the produced executable
        // Свойства созданного исполняемого файла
        fileTagsFilter: product.type
        qbs.install: true
    }

    // Создать .bin файл
    // Create a .bin file
    Rule {
        id: binDebugFrmw
        condition: qbs.buildVariant === "debug"
        inputs: ["application"]

        Artifact {
            fileTags: ["bin"]
            filePath: input.baseDir + "/" + input.baseName + ".bin"
        }

        prepare: {
            var objCopyPath = "arm-none-eabi-objcopy"
            var argsConv = ["-O", "binary", input.filePath, output.filePath]
            var cmd = new Command(objCopyPath, argsConv)
            cmd.description = "converting to BIN: " + FileInfo.fileName(
                        input.filePath) + " -> " + input.baseName + ".bin"

//            // Запись в nor память по qspi
//            // Write to the nor memory by qspi
//            var argsFlashingQspi =
//            [           "-f", "/usr/local/share/openocd/scripts/target/stm32f1x.cfg",
//                          "-f", "/usr/local/share/openocd/scripts/interface/stlink-v2.cfg",
//                        "-c", "init",
//                        "-c", "reset init",
//                        "-c", "flash write_bank 1 " + output.filePath + " 0",
//                        "-c", "reset",
//                        "-c", "shutdown"
//            ]
//
//            var cmdFlashQspi = new Command("openocd", argsFlashingQspi);
//            cmdFlashQspi.description = "Wrtie to the NOR QSPI 1"
//
//            // Запись во внутреннюю память
//            // Write to the internal memory

              var argsFlashingInternalFlash =
            [           //"-f", "/usr/local/share/openocd/scripts/target/stm32f1x.cfg",
                        //"-f", "/usr/local/share/openocd/scripts/interface/stlink-v2.cfg",
                        "-f", "/home/maxx/Project/robot/stm32f103/openocd.cfg",
                        "-c", "init",
                        "-c", "reset init",
                        "-c", "flash write_image erase " + input.filePath ,
           //  "-c erase",
            // "-c","flash" + input.filePath,
                        "-c", "reset",
                        "-c", "shutdown"
            ]

            var cmdFlashInternalFlash = new Command("openocd", argsFlashingInternalFlash);
            cmdFlashInternalFlash.description = "Wrtie to the internal flash"

         //   return [cmd, cmdFlashQspi, cmdFlashInternalFlash]
            return [cmd,  cmdFlashInternalFlash]
        }
    }

    // Создать .bin файл
    // Create a .bin file
    Rule {
        id: binFrmw
        condition: qbs.buildVariant === "release"
        inputs: ["application"]

        Artifact {
            fileTags: ["bin"]
            filePath: input.baseDir + "/" + input.baseName + ".bin"
        }

        prepare: {
            var objCopyPath = "arm-none-eabi-objcopy"
            var argsConv = ["-O", "binary", input.filePath, output.filePath]
            var cmd = new Command(objCopyPath, argsConv)
            cmd.description = "converting to BIN: " + FileInfo.fileName(
                        input.filePath) + " -> " + input.baseName + ".bin"

            // Запись в nor память по qspi
            // Write to the nor memory by qspi
//            var argsFlashingQspi =
//            [           "-f", "/usr/local/share/openocd/scripts/target/stm32f1x.cfg",
//                        "-c", "init",
//                        "-c", "reset init",
//                        "-c", "flash write_bank 1 " + output.filePath + " 0",
//                        "-c", "reset",
//                        "-c", "shutdown"
 //           ]
//
//            var cmdFlashQspi = new Command("openocd", argsFlashingQspi);
//            cmdFlashQspi.description = "Wrtie to the NOR QSPI"

            // Запись во внутреннюю память
            // Write to the internal memory
            var argsFlashingInternalFlash =
            [         //  "-f", "/usr/local/share/openocd/scripts/target/stm32f1x.cfg",
                      //  "-f", "/usr/local/share/openocd/scripts/interface/stlink-v2.cfg",
                        "-f", "/home/maxx/Project/robot/stm32f103/openocd.cfg",
                        "-c", "init",
                        "-c", "reset init",
                        "-c", "flash write_image erase " + input.filePath ,
                      //"-c erase",
                     // "-c" + input.filePath,
                         "-c", "reset",
                        "-c", "shutdown"
            ]

            var cmdFlashInternalFlash = new Command("openocd", argsFlashingInternalFlash);
            cmdFlashInternalFlash.description = "Wrtie to the internal flash"
//
//            return [cmd, cmdFlashQspi, cmdFlashInternalFlash]
            return [cmd,  cmdFlashInternalFlash]
        }
    }

    // Создать .hex файл
    // Create a .hex file
    Rule {
        id: hexFrmw
        condition: qbs.buildVariant === "release"
        inputs: ["application"]

        Artifact {
            fileTags: ["hex"]
            filePath: input.baseDir + "/" + input.baseName + ".hex"
        }

        prepare: {
            var objCopyPath = "arm-none-eabi-objcopy"
            var argsConv = ["-O", "ihex", input.filePath, output.filePath]
            var cmd = new Command(objCopyPath, argsConv)
            cmd.description = "converting to HEX: " + FileInfo.fileName(
                        input.filePath) + " -> " + input.baseName + ".hex"

            return [cmd]
        }
    }
}
