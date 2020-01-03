import os

from settings import * 
from time import gmtime, strftime

class FileWriter:

    # Private attributes
    _file = None
    _file_path = ARCH_PATH

    def __init__(self):
        self._file = open(os.path.join(self._file_path, str(strftime("%Y%m%d", gmtime())) + "___psstore_games"), "w+")

    def write(self, content):
        # This method writes content to the file
        
        try:
            self._file.write(content)
        except IOError:
            print("File not accessible")

    def end(self):
        # This method closes the file

        self._file.close()


