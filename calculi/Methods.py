from textual.app import App, ComposeResult
from textual.widgets import Label, RadioButton, RadioSet, Input, TabbedContent, TabPane
from textual_slider import Slider
from textual.containers import Horizontal, Vertical, Container
from textual import on
def pr(x):
        import sys

        orig_stdout = sys.stdout
        f = open('out.txt', 'a')
        sys.stdout = f

        print(x)

        sys.stdout = orig_stdout
        f.close()
        #selected_label = selected_radio_button.label
        #self.update_input_label(selected_label)
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
    def on_radio_set_changed(self, event):
        #import sys

        #orig_stdout = sys.stdout
        #f = open('out.txt', 'w')
        #sys.stdout = f

        self.update_input_label(event.pressed.id)

        #sys.stdout = orig_stdout
        #f.close()
        #selected_label = selected_radio_button.label
        #self.update_input_label(selected_label)

    def update_input_label(self, text):
        input_label = self.app.query_one("#top_label")
        self.app.selected = text

        match text:
            case "jacobi":
                input_label.update("Jacobi iterative method selected")
            case "gauss_seidel":
                input_label.update("Gauss-Seidel iterative method selected")
            case "gauss_elimination":
                input_label.update("Gauss elimination selected")
            case "gauss_jordan":
                input_label.update("Gauss-Jordan elimination selected")
            case "lu_factorization":
                input_label.update("LU factorization selected")
            case "bi_section":
                input_label.update("Bi-section method selected")
            case "false_position":
                input_label.update("False position method selected")
            case "secant":
                input_label.update("Secant method selected")
            case "newton_raphson":
                input_label.update("Newton-Raphson method selected")
            case "runge_kutta":
                input_label.update("Runge-Kutta method selected")
            case "matrix_inversion":
                input_label.update("Matrix Inversion selected")
            case _:
                input_label.update("Unknown method selected")
