# -*- coding: utf-8 -*-
from file_writer import *

class PsstorePipeline(object):
    # Class that serves as pipeline to process each of the saved data items

    def process_item(self, item, spider):
        """ Processes the item being currently scraped """

        write_archive(item['game_name'].encode("utf-8") + " | " \
                            + item['game_price'].encode("utf-8"))

        return item
