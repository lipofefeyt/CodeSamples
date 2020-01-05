# -*- coding: utf-8 -*-
from file_writer import FileWriter

class PsstorePipeline(object):
    # Class that serves as pipeline to process each of the saved data items

    # Private attributes
    _filewriter = FileWriter()

    def process_item(self, item, spider):

        self._filewriter.write(item['game_name'].encode("utf-8") + " | " \
                            + item['game_price'].encode("utf-8") + "\n")

        return item
