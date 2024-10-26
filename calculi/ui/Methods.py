from textual.app import App, ComposeResult
from textual.widgets import Label, RadioButton, RadioSet, Input, TabbedContent, TabPane
from textual_slider import Slider
from textual.containers import Horizontal, Vertical, Container

class Methods(Container):
    def compose(self):
        with TabbedContent():
            with TabPane("Linear"):
                with RadioSet():
                    yield Label("Approximate", classes="spaced")
                    yield RadioButton("Jacobi iterative method", id="jacobi")
                    yield RadioButton("Gauss-Seidel iterative method", id="gauss_seidel")
                    yield Label("Exact", classes="spaced")
                    yield RadioButton("Gauss elimination", id="gauss_elimination")
                    yield RadioButton("Gauss-Jordan elimination", id="gauss_jordan")
                    yield Label("For Edge Devices", classes="spaced")
                    yield RadioButton("LU factorization", id="lu_factorization")
            with TabPane("Non Linear"):
                with RadioSet():
                    yield Label("Bracketing", classes="spaced")
                    yield RadioButton("Bi-section method", id="bi_section")
                    yield RadioButton("False position method", id="false_position")
                    yield Label("Open Ended", classes="spaced")
                    yield RadioButton("Secant method", id="secant")
                    yield RadioButton("Newton-Raphson method", id="newton_raphson")
            with TabPane("Differential"):
                with RadioSet():
                    yield Label("Solution of Differential Equations", classes="spaced")
                    yield RadioButton("Runge-Kutta method", id="runge_kutta")
            with TabPane("Matrix"):
                with RadioSet():
                    yield Label("Matrix Inversion", classes="spaced")
                    yield RadioButton("Matrix Inversion", id="matrix_inversion")

    def on_mount(self):
        for radio_button in self.query(RadioButton):
            radio_button.on_click(self.on_radio_button_click)

    def on_radio_button_click(self, event):
        selected_radio_button = event.sender
        selected_label = selected_radio_button.label
        self.update_input_label(selected_label)

    def update_input_label(self, text):
        input_label = self.app.query_one(Label, id="top_label")
        input_label.update(text)