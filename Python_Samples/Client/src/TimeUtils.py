'''
Created on 16/07/2018

@author: ggsg
'''
import time

# The current time
current_time = 0

class TimeUtils:
    """
    Class that manages time aspects for the application
    """
    
    
    def __init__(self):
        """
        Default constructor for the class TimeUtils
        """
        self.current_time = time.ctime()
        
    def get_time(self):
        """
        Gets the current time formatted as %Y%m%d_%H%M%S
        """
        return time.strftime("%Y%m%d_%H%M%S")
        
