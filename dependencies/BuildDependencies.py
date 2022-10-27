import pathlib
from pathlib import Path
import subprocess
from termcolor import colored
import shutil
import os
import glob

# TODO: Check that we are in dependencies folder
# TODO: Check that cmake is installed

libDir = "lib/x64/"
includeDir = "include/"

# Library list
# ( name, [includes], override for the library file )
libraries = [
    {
        "Name": "pugixml",
        "IncludeFiles": ["src/pugixml.hpp", "src/pugiconfig.hpp"],
        "LibFiles": ["libpugixml.a"],
    },
    {
        "Name": "spdlog",
        "IncludeFiles": ["include/spdlog/**"],
        "LibFiles": ["libspdlog.a"],
    },
    {
        "Name": "glfw",
        "IncludeFiles": ["include/GLFW/**"],
        "LibFiles": ["src/libglfw3.a"],
    },
    {
        "Name": "vex-glad",
        "IncludeFiles": ["glad/include/**"],
        "LibFiles": ["libglad.a"],
        "IncludeOutputOverride": ""
    },
]

# Generate the output folders
print("Generating output directories")
Path(libDir).mkdir(parents=True, exist_ok=True)
Path(includeDir).mkdir(parents=True, exist_ok=True)

libraryCount = len(libraries)


# Compile cmake type dependency
def compile_cmake(index, lib_entry):
    # TODO: Check that library directory exists
    # TODO: Error check

    print("\n")
    print(colored("{} {}/{}".format(lib_entry["Name"], index, libraryCount), "green"))

    lib_dir = "{}/{}".format(os.getcwd(), lib_entry["Name"])
    build_path = "{}/build/".format(lib_dir)

    if "IncludeOutputOverride" in lib_entry:
        include_path = "{}{}/".format(includeDir, lib_entry["IncludeOutputOverride"])
    else:
        include_path = "{}{}/".format(includeDir, lib_entry["Name"])

    print("Build path:", build_path)

    Path(build_path).mkdir(parents=True, exist_ok=True)

    print("Generating cmake")
    cmake = subprocess.Popen(["cmake", ".."], cwd=build_path)
    cmake.wait()

    print("Compiling")
    cmake = subprocess.Popen(["make", "-j8"], cwd=build_path)
    cmake.wait()

    # Copy over necessary files
    Path(include_path).mkdir(parents=True, exist_ok=True)

    for lib in lib_entry["LibFiles"]:
        shutil.copy("{}{}".format(build_path, lib), libDir)

    for include_file in lib_entry["IncludeFiles"]:
        if "*" in include_file:
            for file in glob.glob("{}/{}".format(lib_dir, include_file)):
                if Path(file).is_dir():
                    shutil.copytree(file, include_path + Path(file).stem, dirs_exist_ok=True)
                else:
                    shutil.copy(file, include_path)
        else:
            shutil.copy("{}/{}".format(lib_dir, include_file), include_path)


# Compile libraries
for i, entry in enumerate(libraries):
    compile_cmake(i + 1, entry)

print("\n")
