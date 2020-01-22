# -*- coding: utf-8 -*-
import os
import logging

from settings import * 
from time import gmtime, strftime

class FileWriter:

    # Private attributes
    _file = None
    _file_path = ARCH_PATH

    def __init__(self):

        # Create archive dir if not present
        if not os.path.exists(ARCH_PATH):
            os.makedirs(ARCH_PATH)
            logging.info("%s was created." %(ARCH_PATH))

        self._file = open(os.path.join(self._file_path, str(strftime("%Y%m%d", gmtime())) + ARCH_NAME_EXT), "w+")

    def write(self, content):
        # This method writes content to the file
        
        try:
            self._file.write(content)
        except IOError:
            logging.error("File not accessible")

    def end(self):
        # This method closes the opened file

        self._file.close()


