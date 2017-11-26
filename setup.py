from distutils.core import setup
from distutils.extension import Extension


turtlerubik_module = Extension(name='_rubik',
                               sources=['src/rubik.cc',
                                        'rubik_wrap.cxx'],
                               include_dirs=['src'],
                               extra_compile_args=['-std=c++11'])

setup(
    name='rubik',
    version='0.0',
    ext_modules=[turtlerubik_module],
    description='Rubik library',
    author='Asier Cardoso',
    py_modules=['rubik'],
)
