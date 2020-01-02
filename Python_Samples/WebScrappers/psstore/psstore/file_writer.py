from time import gmtime, strftime

class FileWriter:

    # Private attributes
    _file = None

    def __init__(self):
        self._file = open(str(strftime("%Y%m%d", gmtime())) + "___psstore_games", "w+")

    # TODO: Add file checks
    def write(self, content):
        self._file.write(content)

    # TODO: Add file checks
    def end(self):
        self._file.close()

