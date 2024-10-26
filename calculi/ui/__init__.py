from textual.app import App, ComposeResult
from textual.widgets import Label, Header, Footer,Static,Button,TextArea
from textual.screen import Screen
from textual.containers import Container,VerticalScroll,HorizontalScroll
from Methods import Methods 
from textual_plotext import PlotextPlot
class Space(Container):
    def compose(self) -> ComposeResult:
        yield Methods()
        with VerticalScroll(classes="inp"):
            yield Label("weiufgh",id="top_label")
            yield TextArea()
            yield Button(label="Solve", id="solve")
            with VerticalScroll():
                yield Static("weiufghweiufghewifiweiufghewifiweiufghewifiweiufghewifiweiufghewifiweiufghewifiweiufghewifiweiufghewifiweiufghewifiweiufghewifiweiufghewifiweiufghewifiweiufghewifiweiufghewifiweiufghewifiweiufghewifiweiufghewifiweiufghewifiweiufghewifiweiufghewifiweiufghewifiweiufghewifiweiufghewifiweiufghewifiweiufghewifiweiufghewifiweiufghewifiweiufghewifiweiufghewifiweiufghewifiweiufghewifiweiufghewifiweiufghewifiweiufghewifiweiufghewifiweiufghewifiweiufghewifiweiufghewifiweiufghewifiweiufghewifiweiufghewifiweiufghewifiweiufghewifiweiufghewifiweiufghewifiweiufghewifiweiufghewifiweiufghewifiweiufghewifiweiufghewifiweiufghewifiweiufghewifiweiufghewifiweiufghewifiweiufghewifiweiufghewifiweiufghewifiweiufghewifiewifi")
        with HorizontalScroll(classes="colsp2"):
            yield PlotextPlot()

class InterFace(Screen):
    def compose(self) -> ComposeResult:
        yield Header(id="Header")
        yield Space()
        yield Footer(id="Footer")  

class Calculi(App):
    CSS_PATH = "styles.tcss"

    def on_mount(self):
        self.push_screen(InterFace())


if __name__ == "__main__":
    app = Calculi()
    app.run()