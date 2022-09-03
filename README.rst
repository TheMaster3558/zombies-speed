zombies-speed
==============
A speed up to `zombies <https://github.com/chawkk6404/zombies>`_ made in C++.
This will add the DLL but not remove any python files. This easily preserves typing.


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

If you get an error that includes this

.. code-block::

    fatal error: pybind11/pybind11.h No such file or directory

Run this

.. code-block:: sh

    pip install pybind11[global]


Code Formatting
----------------
All code should be formatted with `black`.
