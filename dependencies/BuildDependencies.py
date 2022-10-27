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

# Generate the output folders
print("Generating output directories")
Path(libDir).mkdir(parents=True, exist_ok=True)
Path(includeDir).mkdir(parents=True, exist_ok=True)

libraryCount = 3


# Compile cmake type dependency
def compile_cmake(index, lib_name, include_files, output_lib_override=None):
    # TODO: Check that library directory exists
    # TODO: Error check

    print("\n")
    print(colored("{} {}/{}".format(lib_name, index, libraryCount), "green"))

    if output_lib_override is None:
        output_file = "lib{}.a".format(lib_name)
    else:
        output_file = "{}.a".format(output_lib_override)

    lib_dir = "{}/{}".format(os.getcwd(), lib_name)
    build_path = "{}/build/".format(lib_dir)
    include_path = "{}{}/".format(includeDir, lib_name)
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

    shutil.copy("{}{}".format(build_path, output_file), libDir)

    for include_file in include_files:
        if "*" in include_file:
            for file in glob.glob("{}/{}".format(lib_dir, include_file)):
                if Path(file).is_dir():
                    shutil.copytree(file, include_path + Path(file).stem, dirs_exist_ok=True)
                else:
                    shutil.copy(file, include_path)
        else:
            shutil.copy("{}/{}".format(lib_dir, include_file), include_path)


# Compile libraries
compile_cmake(1, "pugixml", ["src/pugixml.hpp", "src/pugiconfig.hpp"])
compile_cmake(2, "spdlog", ["include/spdlog/**"])
compile_cmake(3, "glfw", ["include/GLFW/**"], output_lib_override="src/libglfw3")

print("\n")
