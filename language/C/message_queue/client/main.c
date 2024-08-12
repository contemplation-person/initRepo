#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>
#include <stdio.h>

#define MSG_SIZE 100

struct msg_buffer
{
    long msg_type;
    char msg_text[MSG_SIZE];
};

int main()
{
    key_t key;
    int msgid;
    struct msg_buffer message;
    char *test_msg;


    key = ftok("snd", 42);
    msgid = msgget(key, 0666| IPC_CREAT);
    message.msg_type = 1;

    test_msg = "hello msg";
    strcpy(message.msg_text, test_msg);
    printf("ready msg: %s\n", message.msg_text);

    msgsnd(msgid, &message, sizeof(message), 0);   
    return 0;
}
