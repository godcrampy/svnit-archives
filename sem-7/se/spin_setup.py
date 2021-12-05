import glob, os, shutil, sys, pathlib

if len(sys.argv) != 3:
    print("Usage: python spin_setup.py <source-dir> <dest-dir>")
    exit()

source_dir = sys.argv[1]
dest_dir = sys.argv[2]

files = glob.iglob(os.path.join(source_dir, "*.pml"))
for file in files:
    if os.path.isfile(file):
        # copy file and append lab number to filename
        shutil.copy2(
            file,
            pathlib.Path(
                dest_dir, pathlib.Path(source_dir).name + "-" + pathlib.Path(file).name
            ),
        )
