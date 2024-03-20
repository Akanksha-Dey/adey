import re
import random

# Define the long responses
R_EATING = "I don't eat because I'm a bot! But I can help you find recipes."
R_ADVICE = "My advice would be to search online for more information about that topic."

def unknown():
    response = ["Could you please re-phrase that?",
                "I'm not sure I understand.",
                "Can you provide more context?",
                "What do you mean by that?"][
        random.randrange(4)]
    return response

def message_probability(user_message, recognised_words, single_response=False, required_words=[]):
    message_certainty = 0
    has_required_words = True

    for word in user_message:
        if word in recognised_words:
            message_certainty += 1

    percentage = float(message_certainty) / float(len(recognised_words))

    for word in required_words:
        if word not in user_message:
            has_required_words = False
            break

    if has_required_words or single_response:
        return int(percentage * 100)
    else:
        return 0

def check_all_messages(message):
    highest_prob_list = {}

    def response(bot_response, list_of_words, single_response=False, required_words=[]):
        nonlocal highest_prob_list
        highest_prob_list[bot_response] = message_probability(message, list_of_words, single_response, required_words)

    response('Hello!', ['hello', 'hi', 'hey', 'sup', 'heyo'], single_response=True)
    response('See you!', ['bye', 'goodbye'], single_response=True)
    response('I\'m doing fine, and you?', ['how', 'are', 'you', 'doing'], required_words=['how'])
    response('You\'re welcome!', ['thank', 'thanks'], single_response=True)
    response('Thank you!', ['i', 'love', 'code', 'palace'], required_words=['code', 'palace'])
    response('How can I assist you?', ['help', 'assist', 'support'], single_response=True)

    # More responses added
    response('That\'s interesting!', ['interesting'], single_response=True)
    response('I don\'t have an opinion on that.', ['opinion', 'think', 'thoughts'], single_response=True)
    response('Let me check that for you.', ['check', 'verify'], required_words=['check'])
    response('Have you tried searching online?', ['search', 'find', 'internet'], required_words=['search', 'online'])
    response('I\'m not programmed to answer that.', ['not', 'programmed', 'answer'], required_words=['not', 'answer'])

    # Add good night and good morning responses
    response('Good night!', ['good', 'night'], single_response=True)
    response('Good morning!', ['good', 'morning'], single_response=True)

    best_match = max(highest_prob_list, key=highest_prob_list.get)
    return unknown() if highest_prob_list[best_match] < 1 else best_match

def get_response(user_input):
    split_message = user_input.lower().split()
    response = check_all_messages(split_message)
    return response

# Testing the response system
while True:
    user_input = input('You: ')
    if user_input.lower() == 'exit':
        print('Bot: Exiting...')
        break
    print('Bot: ' + get_response(user_input))
