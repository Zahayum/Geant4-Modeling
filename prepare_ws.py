#!/usr/bin/python3
import os
import shutil

wd = os.getcwd()
templates_dir = os.path.join(wd, "templates")
vscode_dir = os.path.join(wd, ".vscode")
build_dir = os.path.join(wd, "build")

try:
    os.mkdir(vscode_dir)
except:
    ...

try:
    shutil.rmtree(build_dir)
except:
    ...



for src, dst in zip(
    [
        os.path.join(templates_dir, "c_cpp_properties.json"),
        os.path.join(templates_dir, "run.mac"),
        os.path.join(templates_dir, "task.md"),
    ], [
        os.path.join(vscode_dir, "c_cpp_properties.json"),
        os.path.join(wd, "run.mac"),
        os.path.join(wd, "task.md"),
    ]
):
    shutil.copy(src, dst)
