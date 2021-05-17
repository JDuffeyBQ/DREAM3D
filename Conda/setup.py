from setuptools import setup, find_packages
from sysconfig import get_config_var

ext = get_config_var('EXT_SUFFIX')

setup(
    name='dream3d',
    version='@DREAM3D_PY_VERSION@',
    packages=find_packages(),
    package_data={'dream3d': [f'*{ext}']},
    include_package_data=True,
    zip_safe=False
)
