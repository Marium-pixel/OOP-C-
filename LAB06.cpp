#include <iostream>
#include <string>
using namespace std;

class Message {
protected:
    string text;
public:
    Message(const string& txt = "") : text(txt) {}
    virtual ~Message() {}
    
    void setText(const string& txt) { text = txt; }
    string getText() const { return text; }
    
    virtual string toString() const { return text; }
};

class SMS : public Message {
private:
    string recipientContactNo;
public:
    SMS(const string& txt, const string& contactNo) : Message(txt), recipientContactNo(contactNo) {}
    
    void setRecipient(const string& contactNo) { recipientContactNo = contactNo; }
    string getRecipient() const { return recipientContactNo; }
    
    string toString() const override {
        return "Recipient: " + recipientContactNo + "\nMessage: " + text;
    }
};

class Email : public Message {
private:
    string sender, receiver, subject;
public:
    Email(const string& txt, const string& snd, const string& rcv, const string& sub)
        : Message(txt), sender(snd), receiver(rcv), subject(sub) {}
    
    void setSender(const string& snd) { sender = snd; }
    void setReceiver(const string& rcv) { receiver = rcv; }
    void setSubject(const string& sub) { subject = sub; }
    
    string getSender() const { return sender; }
    string getReceiver() const { return receiver; }
    string getSubject() const { return subject; }
    
    string toString() const override {
        return "From: " + sender + "\nTo: " + receiver + "\nSubject: " + subject + "\nMessage: " + text;
    }
};

bool ContainsKeyword(const Message& messageObject, const string& keyword) {
    return messageObject.getText().find(keyword) != string::npos;
}

string EncodeMessage(const string& message) {
    string encoded = message;
    for (char& ch : encoded) {
        if ((ch >= 'a' && ch <= 'y') || (ch >= 'A' && ch <= 'Y')) ch++;
        else if (ch == 'z') ch = 'a';
        else if (ch == 'Z') ch = 'A';
    }
    return encoded;
}

int main() {
    SMS sms("Hello, this is a test message.", "+1234567890");
    cout << "SMS: \n" << sms.toString() << "\n\n";
    
    Email email("Meeting at 10 AM.", "alice@example.com", "bob@example.com", "Meeting Reminder");
    cout << "Email: \n" << email.toString() << "\n\n";
    
    string keyword = "test";
    cout << "Keyword '" << keyword << "' in SMS: " << (ContainsKeyword(sms, keyword) ? "Found" : "Not Found") << "\n";
    
    string originalText = "This is Java";
    cout << "Original: " << originalText << "\nEncoded: " << EncodeMessage(originalText) << "\n";
    
    return 0;
}
