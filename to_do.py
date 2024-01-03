import tkinter as tk
import datetime as dt

class TodoApp:
    def __init__(self, master):
        self.master = master
        self.master.title("Todo List")
        self.tasks = []
        self.reminders = {}
        
        # Create the widgets
        self.task_label = tk.Label(master, text="Task:")
        self.task_entry = tk.Entry(master)
        self.date_label = tk.Label(master, text="Date (YYYY-MM-DD):")
        self.date_entry = tk.Entry(master)
        self.time_label = tk.Label(master, text="Time (HH:MM):")
        self.time_entry = tk.Entry(master)
        self.add_button = tk.Button(master, text="Add Task", command=self.add_task)
        self.task_list = tk.Listbox(master)
        
        # Add the widgets to the grid
        self.task_label.grid(row=0, column=0, sticky="w")
        self.task_entry.grid(row=0, column=1)
        self.date_label.grid(row=1, column=0, sticky="w")
        self.date_entry.grid(row=1, column=1)
        self.time_label.grid(row=2, column=0, sticky="w")
        self.time_entry.grid(row=2, column=1)
        self.add_button.grid(row=3, column=1)
        self.task_list.grid(row=4, columnspan=2)
        
        # Set the column weights to expand the widgets
        self.master.columnconfigure(0, weight=1)
        self.master.columnconfigure(1, weight=1)
        
        # Start the main loop
        self.master.mainloop()
    
    def add_task(self):
        # Get the task, date, and time from the entries
        task = self.task_entry.get()
        date_str = self.date_entry.get()
        time_str = self.time_entry.get()
        
        # Parse the date and time strings into a datetime object
        datetime_str = f"{date_str} {time_str}"
        try:
            deadline = dt.datetime.strptime(datetime_str, "%Y-%m-%d %H:%M")
        except ValueError:
            tk.messagebox.showerror("Invalid Input", "Please enter a valid date and time.")
            return
        
        # Add the task to the list and the listbox
        self.tasks.append(task)
        self.task_list.insert(tk.END, task)
        
        # Set a reminder for the task
        self.reminders[task] = deadline
        self.set_reminder(task, deadline)
        
        # Clear the entries
        self.task_entry.delete(0, tk.END)
        self.date_entry.delete(0, tk.END)
        self.time_entry.delete(0, tk.END)
    
    def set_reminder(self, task, deadline):
        # Calculate the time until the deadline
        now = dt.datetime.now()
        time_left = deadline - now
        
        # If the deadline has already passed, don't set a reminder
        if time_left <= dt.timedelta():
            return
        
        # Convert the time left to milliseconds
        time_left_ms = int(time_left.total_seconds() * 1000)
        
        # Set the reminder using the after() method
        self.master.after(time_left_ms, self.remind, task)
    
    def remind(self, task):
        # Display a reminder message
        tk.messagebox.showinfo("Reminder", f"It's time to do {task}!")
        
        # Remove the task from the list and the dictionary
        self.tasks.remove(task)
