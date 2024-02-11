import os
from datetime import date
from PyQt6.QtCore import *
from PyQt6.QtWidgets import *

class WidgetGallery(QDialog):

    def __init__(self, parent=None):
        super(WidgetGallery, self).__init__(parent)

        self.display_window = QVBoxLayout()

        self.text_edit = QTextEdit()
        self.text_edit.setMaximumHeight(100)
        self.text_edit.setMinimumHeight(50)

        save_button = QPushButton()
        save_button.setText("SAVE")
        save_button.setFlat(True)
        save_button.clicked.connect(self.save)

        bottom_layout = QHBoxLayout()
        bottom_layout.addWidget(self.text_edit)
        bottom_layout.addWidget(save_button)

        main_layout = QGridLayout()
        main_layout.addLayout(self.display_window,0,0,alignment=Qt.AlignmentFlag.AlignTop)
        main_layout.addLayout(bottom_layout,1,0,alignment=Qt.AlignmentFlag.AlignBottom)
        self.setLayout(main_layout)
        self.setWindowTitle("Chitragupt")
        self.load_display_window()

    def load_display_window(self):
        current_date = date.today()
        filename = f"./{current_date}.md"
        file_exists = os.path.exists(filename)
        if(file_exists):
            with open(filename,'r') as fptr:
                while(newline := fptr.readline()):
                    newline = newline.strip()
                    new_label = QLabel(newline)
                    new_label.setStyleSheet("background-color: coral;border: 1px solid brown; border-radius: 5px;")
                    self.display_window.addWidget(new_label)
        else:
            new_label = QLabel("no-content")
            self.display_window.addWidget(new_label)

    def save(self):
        current_date = date.today()
        filename = f"./{current_date}.md"
        content = self.text_edit.toPlainText()
        with open(filename,'a') as fptr:
            fptr.write(content + "\n")
        new_label = QLabel(content)
        new_label.setStyleSheet("background-color: coral;border: 1px solid brown; border-radius: 5px;")
        self.display_window.addWidget(new_label)
        self.text_edit.setPlainText("")

if __name__ == "__main__":

    import sys

    app = QApplication(sys.argv)
    app.setStyle("Fusion")

    gallery = WidgetGallery()
    gallery.show()

    sys.exit(app.exec())
