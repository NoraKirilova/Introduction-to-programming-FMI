const char TERMINATE_SYMBOL = '\0';

unsigned myStrLen(const char* str) {
	if (!str) {
		return 0;
	}

	unsigned index = 0;
	while (str[index] != TERMINATE_SYMBOL) {
		index++;
	}

	return index;
}

int myStrCmp(const char* first, const char* second) {
	if (!first || !second) {
		return -1; // error value
	}

	while (*first && *first == *second) {
		first++;
		second++;
	}
	
	return *first - *second;
}

void myStrCpy(char* destination, const char* source) {
	if (!destination || !source) {
		return;
	}
	
	// we assume there is enough space in destination
	while (*source) {
		*destination = *source;
		destination++;
		source++;
	}
	*destination = TERMINATE_SYMBOL;
}

void myStrCat(char* destination, const char* source) {
	if (!destination || !source) {
		return;
	}

	// we assume there is enough space in destination
	unsigned length = myStrLen(destination);
	destination += length;
	myStrCpy(destination, source);
}

unsigned getCharOccurrencesCount(const char* text, char ch) {
	if (!text) {
		return 0;
	}

	unsigned counter = 0;
	while (*text) {
		if (*text == ch) {
			counter++;
		}

		text++;
	}

	return counter;
}

bool isDigit(char ch) {
	return '0' <= ch && ch <= '9';
}

unsigned stringToUnsignedInteger(const char* numberString) {
	if (!numberString) {
		return 0; // error value
	}

	unsigned result = 0;
	while (*numberString) {
		char ch = *numberString;
		if (!isDigit(ch)) {
			return 0; // error value
		}
		result *= 10;
		result += (ch - '0');
		numberString++;
	}

	return result;
}

bool isPrefix(const char* text, const char* expectedPrefix) {
	if (!text || !expectedPrefix) {
		return false;
	}

	while (*expectedPrefix) {
		if (*text != *expectedPrefix) {
			return false;
		}
		text++;
		expectedPrefix++;
	}

	return true;
}

bool searchInText(const char* text, const char* searchedText) {
	if (!text || !searchedText) {
		return false;
	}

	while (*text) {
		if (isPrefix(text, searchedText)) {
			return true;
		}

		text++;
	}

	return false;
}

bool searchInText2(const char* text, const char* searchedText) {
	if (!text || !searchedText) {
		return false;
	}

	unsigned textLength = myStrLen(text);
	unsigned searcheTextLength = myStrLen(searchedText);
	while(searcheTextLength <= textLength) {
		if (isPrefix(searchedText, text)) {
            		return true;
        	}
        
		text++;
		textLength--;
	}

	return false;
}
