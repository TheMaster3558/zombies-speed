from setuptools import setup, Extension


with open("requirements.txt", "r") as file:
    requirements = file.read().splitlines()
    print(requirements)

with open("README.rst", "r") as file:
    readme = file.read()


extensions = [Extension("zombies_speed", ["zombies_speed.cpp"], language="c++")]


setup(
    name="zombies_speed",
    version="1.0.0a",
    author="The Master",
    license="MIT",
    description="A speedup for zombies.",
    long_description=readme,
    long_description_content_type="text/x-rst",
    ext_modules=extensions,
    install_requires=requirements,
)
