def damage(lostHeart, heart):

    """
    For the damage !
    :param lostHeart: When player lose heart !
    :param heart: Player heart !
    :return:
    """
    
    while lostHeart < player.heart:
        heart -= 1


def player(heart):

    """
    For the player in him
    :param heart: Player heart !
    :return:
    """
    
    player.heart = 20

    if player.heart < 0:
        return False
    elif player.heart > 20:
        return False

def life(heart, maxLife, minLife):

    """
    For the player life !
    :param heart: player heart in real time x)
    :param maxLife: 20 is the max Life for a basic player
    :param minLife: 0 is the min Life for a basic player
    :return:
    """

    maxLife = 20
    minLife = 0
    heart = player.heart
