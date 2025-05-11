import tkinter as tk
from chatbot import query_process

def chat():
    user_input = user_entry.get()
    chat_log.config(state=tk.NORMAL)

    chat_log.tag_config("user",justify="right",foreground="blue")
    chat_log.tag_config("bot",justify="left",foreground="green")

    chat_log.insert(tk.END,"You: "+user_input+"\n",'user')

    if user_input.strip() == "":
        return

    if user_input.lower() in ["bye","exit","quit"]:
        chat_log.insert(tk.END,"Bot: ","Thanks for visiting us! Goodbye!","\n")
        chat_log.config(state=tk.DISABLED)
        root.after(3000,root.destroy)
        return
    
    response = query_process(user_input)
    chat_log.insert(tk.END,"Bot: "+response+"\n\n",'bot')
    chat_log.config(state=tk.DISABLED)
    user_entry.delete(0,tk.END)



#GUI setup
root = tk.Tk()
root.title("TeleTree Restaurant Chatbot")
root.geometry("400x600")

chat_log = tk.Text(root,bd=1,bg="White", font=("Arial",12))
chat_log.config(state=tk.DISABLED)
chat_log.pack(pady=10,padx=10,fill=tk.BOTH,expand=True)

user_entry = tk.Entry(root,bd=1,font=("Arial",12))
user_entry.pack(pady=10,padx=10,fill=tk.X)

send_button = tk.Button(root,text="Send",command=chat,bg="Green",fg="white",font=("Arial",12))
send_button.pack(pady=5)

root.mainloop()