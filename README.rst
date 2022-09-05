zombies-speed
==============
A speed up to `zombies <https://github.com/chawkk6404/zombies>`_ made in C++.
It is ~35 times faster the the pure python module.


License
--------
MIT


Installation
-------------
First install `pybind11`

.. code-block:: sh

    $ pip install pybind11

Then install this package

.. code-block:: sh

    $ pip install zombies-speed

If you get an error that has this in it (Usually happens when you are inside a Virtual Env)

.. code-block::

    fatal error: pybind11/pybind11.h No such file or directory

Run this and try again

.. code-block:: sh

    pip install pybind11[global]


Code Formatting
----------------
All code should be formatted with `black`.
