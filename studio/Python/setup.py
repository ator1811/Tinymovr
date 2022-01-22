
import pathlib
from setuptools import setup, find_packages

# The directory containing this file
HERE = pathlib.Path(__file__).parent

# The text of the README file
README = (HERE / "README.md").read_text()

setup(
    name="tinymovr",
    version="0.4.0",
    author="Yannis Chatzikonstantinou",
    author_email="info@tinymovr.com",
    description="Tinymovr Studio",
    long_description=README,
    long_description_content_type="text/markdown",
    url="https://github.com/yconst/Tinymovr",
    packages=find_packages(include=['tinymovr', 'tinymovr.*']),
    classifiers=[
        "Programming Language :: Python :: 3",
        "License :: OSI Approved :: GNU General Public License v3 or later (GPLv3+)",
        "Operating System :: OS Independent",
    ],
    python_requires='>=3.6',
    install_requires=[
        "ipython",
        "pyside2",
        "pyqtgraph",
        "pyserial",
        "python-can>=4.0.0.dev0",
        #"python-can @ git+https://github.com/yconst/python-can.git@develop#egg=python-can-dev",
        "can-isotp",
        "avlos @ git+ssh://git@github.com/tinymovr/avlos-client.git@main#egg=avlos"
        "pyserial",
        "docopt",
        "humanfriendly",
        "pint"
    ],
    entry_points={
        "console_scripts": [
            "tinymovr_cli=tinymovr.shell:spawn_shell",
            "tinymovr=tinymovr.gui:spawn_gui"
        ],
        "can.interface": [
            "sim=tests:SimBus",
        ]
    }
)
