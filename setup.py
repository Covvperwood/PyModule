from distutils.core import setup
from distutils.extension import Extension
mvnlibmodule = Extension(name="mvnlib", sources=['mvnlib.c', ])
setup(name="mvnlib", ext_modules=[mvnlibmodule])
