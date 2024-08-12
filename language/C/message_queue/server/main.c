
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

    key = ftok("snd", 42);
    msgid = msgget(key, 0666 | IPC_CREAT);
    msgrcv(msgid, &message, sizeof(message), 1, 0);
    printf("server : %s\n", message.msg_text);
    msgctl(msgid, IPC_RMID, NULL);
}
