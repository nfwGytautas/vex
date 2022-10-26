from pathlib import Path
import subprocess
from termcolor import colored
import shutil
import os

# TODO: Check that we are in dependencies folder
# TODO: Check that cmake is installed

libDir = "lib/x64/"
includeDir = "include/"

# Generate the output folders
print("Generating output directories")
Path(libDir).mkdir(parents=True, exist_ok=True)
Path(includeDir).mkdir(parents=True, exist_ok=True)

libraryCount = 1


# pugixml
def compile_pugixml():
    # TODO: Check that pugixml directory exists
    # TODO: Error check

    lib_name = "pugixml"
    output_file = "libpugixml.a"

    lib_dir = "{}/{}".format(os.getcwd(), lib_name)
    build_path = "{}/build/".format(lib_dir)
    include_path = "{}{}/".format(includeDir, lib_name)

    print("\n")
    print(colored("pugixml 1/{}".format(libraryCount), "green"))

    Path("pugixml/build/").mkdir(parents=True, exist_ok=True)

    print("Generating cmake")
    cmake = subprocess.Popen(["cmake", ".."], cwd=build_path)
    cmake.wait()

    print("Compiling")
    cmake = subprocess.Popen(["make", "-j8"], cwd=build_path)
    cmake.wait()

    # Copy over necessary files
    Path(include_path).mkdir(parents=True, exist_ok=True)

    shutil.copy("{}{}".format(build_path, output_file), libDir)

    shutil.copy("{}/src/pugixml.hpp".format(lib_dir), include_path)
    shutil.copy("{}/src/pugiconfig.hpp".format(lib_dir), include_path)


# Compile libraries
compile_pugixml()

print("\n")
