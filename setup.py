from setuptools import setup, Extension

setup(
    ext_modules=[
        Extension("example", sources=["src/example.c"]),
    ],
)
