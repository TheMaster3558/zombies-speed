import setuptools


with open('requirements.txt', 'r') as file:
    requirements = file.readlines()


with open('README.rst', 'r') as file:
    readme = file.read()


packages = ['zombies']


extensions = [
    setuptools.Extension('zombies.zombies', ['zombies/zombies.c'])
]


setuptools.setup(
    name='zombies-speed',
    version='1.0.0a',
    author='The Master',
    license='MIT',
    description="A speedup for zombies.",
    long_description=readme,
    long_description_content_type="text/x-rst",
    packages=packages,
    ext_modules=extensions
)
