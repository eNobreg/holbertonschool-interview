#!/usr/bin/python3

def count_words(subreddit, word_list, after='', result_dict={}):
    """ recursive function """
    import requests

    url = "https://www.reddit.com/r/{}/hot.json".format(subreddit)
    user_agent = "person_with_things"
    header = {"User-Agent": user_agent}
    resp = requests.get(url, headers=header, allow_redirects=False,
                        params={'after': after, 'limit': 100})
    if (resp.status_code != 200):
        return(None)
    else:
        data = resp.json()["data"]
        children = data["children"]
        for entry in children:
            for word in word_list:
                word = word.lower()
                word_count = entry["data"]["title"].lower().split().count(word)
                if  word_count > 0:
                    if word not in result_dict.keys():
                        result_dict[word] = 0
                    else:
                        result_dict[word] += word_count
        after = data["after"]
        if after is None:
            for k, v in sorted(result_dict.items(), key=lambda item: item[1],reverse=True):
                print("{}: {}".format(k, v))
            return result_dict
        else:
            return count_words(subreddit, word_list, after, result_dict)