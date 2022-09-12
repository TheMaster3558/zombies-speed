from setuptools import setup, Extension


try:
    import pybind11
except ImportError:
    raise ImportError(
        "pybind11 must be installed with pip install pybind11 or pip install pybind11[global]"
    )


with open("requirements.txt", "r") as file:
    requirements = file.read().splitlines()

with open("README.rst", "r") as file:
    readme = file.read()


extensions = [Extension("zombies.zombies", ["zombies.cpp"], language="c++")]


setup(
    name="zombies-speed",
    version="1.0.0a",
    author="The Master",
    license="MIT",
    description="A speedup for zombies.",
    long_description=readme,
    long_description_content_type="text/x-rst",
    ext_modules=extensions,
    install_requires=requirements,
)
