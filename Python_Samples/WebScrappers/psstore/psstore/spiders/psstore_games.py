# -*- coding: utf-8 -*-
import scrapy

class PsstoreGamesSpider(scrapy.Spider):
    
    # Private attributes
    name = 'psstore_games'
    allowed_domains = ['https://store.playstation.com/fr-be/grid/STORE-MSF75508-PS4CAT/1?emcid=em-st-231260&et_cid=em_384465&et_rid=13278658']
    # start_urls = [
    #     'https://store.playstation.com/fr-be/grid/STORE-MSF75508-PS4CAT/1?emcid=em-st-231260&et_cid=em_384465&et_rid=13278658/',
    #     'https://store.playstation.com/fr-be/grid/STORE-MSF75508-PS4CAT/2?emcid=em-st-231260&et_cid=em_384465&et_rid=13278658/',
    #     'https://store.playstation.com/fr-be/grid/STORE-MSF75508-PS4CAT/3?emcid=em-st-231260&et_cid=em_384465&et_rid=13278658/'
    # ]
    start_urls = []

    # FIXME: This will be changed once we know how to get all the pages from the PSN
    num_pages = 133

    # Build all the urls
    pre_url = 'https://store.playstation.com/fr-be/grid/STORE-MSF75508-PS4CAT/'
    post_url = '?emcid=em-st-231260&et_cid=em_384465&et_rid=13278658/'
    for i in range(1, num_pages):
        start_urls.append(pre_url + str(i) + post_url)

    def parse(self, response):
        
        # # CSS Products
        products = response.css(".grid-cell__body::text")

        # Get each game
        game_titles = response.xpath('//div[@class="grid-cell__title "]/span/text()').extract()  
        game_prices = response.xpath('//div[@class="__shared-presentation__price-display__900cc __shared-presentation__price-display__900cc __shared-presentation__price-display__900cc--grid ember-view"]/h3/text()').extract()

        # FIXME: We cannot use this line only, since some games are free and the H3 tag changes the class name. Hence we get the parent 
        # game_prices = response.xpath('//h3[@class="price-display__price"]/text()').extract()
        
        # print(len(game_titles))
        # print(len(game_prices))

        # Create the catalog
        psn_data = zip(game_titles, game_prices)

        for data in psn_data:

            game_catalog = {
                # 'url' : response.url,
                'game' : data[0],
                'price' : data[1]
            } 

            yield game_catalog