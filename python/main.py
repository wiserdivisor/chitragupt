import os
import json
from datetime import date
from PyQt6.QtCore import *
from PyQt6.QtWidgets import *

class TextArea(QTextEdit):
    def __init__(self,parent):
        super().__init__(parent=parent)
        self.show()
    def keyPressEvent():

class WidgetGallery(QDialog):

    def __init__(self, parent=None):
        super(WidgetGallery, self).__init__(parent)

        top_layout = QVBoxLayout()
        mid_layout = QHBoxLayout()
        btm_layout = QHBoxLayout()

        quote = QLabel()
        quote.setText("Better to be a smart fella than to be a fart smella")
        quote.setStyleSheet("font-size:12px; padding:10px;")
        quote.setAlignment(Qt.AlignmentFlag.AlignCenter)
        top_layout.addWidget(quote)

        self.log_frame = QVBoxLayout()
        self.todo_frame = QVBoxLayout()
        mid_layout.addLayout(self.log_frame)
        mid_layout.addLayout(self.todo_frame)

        self.log_label_style = "color:black; background-color: coral; border: 1px solid brown; border-radius: 5px; padding: 10px; font-size: 16px;"
        self.todo_label_style = "color:black; background-color: skyblue; border: 1px solid brown; border-radius: 5px; padding: 10px; font-size: 16px;"
        self.record_template = { "timestamp":"", "text":""  }

        self.text_edit = QTextEdit()
        self.text_edit.setMaximumHeight(100)
        self.text_edit.setMinimumHeight(50)

        save_button = QPushButton()
        save_button.setText("SAVE")
        save_button.setFlat(True)
        save_button.clicked.connect(self.save)

        btm_layout.addWidget(self.text_edit)
        btm_layout.addWidget(save_button)

        main_layout = QGridLayout()
        main_layout.addLayout(top_layout,0,0,alignment=Qt.AlignmentFlag.AlignTop)
        main_layout.addLayout(mid_layout,1,0)
        main_layout.addLayout(btm_layout,2,0,alignment=Qt.AlignmentFlag.AlignBottom)
        self.setLayout(main_layout)
        self.setWindowTitle("Chitragupt")
        self.load_log_frame()
        self.resize(640,480)

    def load_log_frame(self):
        current_date = date.today()
        filename = f"./{current_date}.md"
        file_exists = os.path.exists(filename)
        if(file_exists):
            with open(filename,'r') as fptr:
                while(newline := fptr.readline()):
                    newline = newline.strip()
                    new_label = QLabel()
                    new_label.setText(newline)
                    new_label.setStyleSheet(self.log_label_style)
                    self.log_frame.addWidget(new_label)

    def open_calendar(self):
        pass

    def save_todo(self,content):
        new_label = QLabel()
        new_label.setText(content)
        new_label.setStyleSheet(self.todo_label_style)
        self.todo_frame.addWidget(new_label)
    
    def save_log(self,content):
        current_date = date.today()
        filename = f"./{current_date}.md"
        with open(filename,'a') as fptr:
            fptr.write(content + "\n")
        new_label = QLabel()
        new_label.setText(content)
        new_label.setStyleSheet(self.log_label_style)
        self.log_frame.addWidget(new_label)


    def goto_date(self,date):
        pass

    def set_reminder(self,timestamp,message):
        pass
    
    def save(self):
        content = self.text_edit.toPlainText()
        content = content.strip()
        if(content[0]==":"):
            print(content)
            content_list = content.split("\n")
            command_args = content_list[0].split(" ")
            match command_args[0]:
                case ":cal":
                    self.open_calendar()
                case ":todo":
                    content_list[1]
                    self.save_todo(content_list[1])
                case ":goto":
                    self.goto_date(command_args[1])
                case ":remind":
                    self.set_reminder(timestamp=command_args[1],message=content_list[1])
                case _:
                    print(f"Unknown Command: {command_args[0]}")
        else:
            self.save_log(content)

        self.text_edit.setPlainText("")

if __name__ == "__main__":

    import sys

    app = QApplication(sys.argv)
    app.setStyle("Fusion")

    gallery = WidgetGallery()
    gallery.show()

    sys.exit(app.exec())
