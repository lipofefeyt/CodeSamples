# -*- coding: utf-8 -*-
import scrapy

class PsstoreItem(scrapy.Item):
    # This class defines an item from the PSN store

    # Get the different fields
    game_name = scrapy.Field()
    game_price = scrapy.Field()
