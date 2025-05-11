import nltk
# nltk.download("all");

from nltk.tokenize import word_tokenize
from nltk.corpus import stopwords
from nltk.stem import WordNetLemmatizer

from nltk.tokenize import word_tokenize
from nltk.corpus import stopwords
from nltk.stem import WordNetLemmatizer

from rules import rules
import random

def query_process(usr_input):
    usr_input = usr_input.lower()

    input_tokens = word_tokenize(usr_input)

    stop_words = set(stopwords.words("english"))

    tokens = []
    for word in input_tokens:
        if word not in stop_words:
            tokens.append(word)

    lemmatizer = WordNetLemmatizer()

    final_tokens = []
    for token in tokens:
        final_tokens.append(lemmatizer.lemmatize(token))

    for keywords,responses in rules.items():
        if set(final_tokens).intersection(keywords):
            return random.choice(responses)
    
    return random.choice(["Can you rephrase?", "Sorry!", "I'm unable to answer that"])
