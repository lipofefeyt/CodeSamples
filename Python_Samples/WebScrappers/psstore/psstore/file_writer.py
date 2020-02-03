# -*- coding: utf-8 -*-
import os
import logging

from settings import * 
from time import gmtime, strftime

# Private attributes
_file = None
_file_path = ARCH_PATH

def write_archive(content):
    """ This method writes content to the file """
    
    # Create archive dir if not present
    if not os.path.exists(ARCH_PATH):
        os.makedirs(ARCH_PATH)
        logging.info("%s was created." %(ARCH_PATH))

    arch_file = open(os.path.join(_file_path, str(strftime("%Y%m%d", gmtime())) + ARCH_NAME_EXT), "w+")

    try:
        arch_file.write(content)
    except IOError:
        logging.error("File not accessible")

    arch_file.close()


