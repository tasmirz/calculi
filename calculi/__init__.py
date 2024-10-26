from textual.app import App, ComposeResult
from textual.widgets import Label, Header, Footer,RichLog,Static,Button,TextArea
from textual.screen import Screen
from textual.containers import Container,VerticalScroll,HorizontalScroll
from Methods import Methods ,pr
from textual_plotext import PlotextPlot
import handler as handler
from textual.logging import TextualHandler
class Vambola(VerticalScroll,):
        def compose(self) -> ComposeResult:
            yield Label("Select a mehtod",id="top_label")
            yield TextArea()
            yield Button(label="Solve", id="solve")
            with VerticalScroll():
                yield RichLog(id="log")
        def on_button_pressed(self, event):
            text_log = self.query_one(RichLog)
            #text_log.write("Button clicked")
            handler.handle_method_selection(self.app.selected,self.query_one(TextArea).text,text_log,self.app.query_one(PlotextPlot).plt)
            #pr(self.query_one(TextArea).text)
            

class Space(Container):
    def compose(self) -> ComposeResult:
        yield Methods()
        yield Vambola()
        with HorizontalScroll(classes="colsp2"):
            yield PlotextPlot()
    

class InterFace(Screen):
    def compose(self) -> ComposeResult:
        yield Header(id="Header")
        yield Space()
        yield Footer(id="Footer")  

class Calculi(App):
    selected = ""
    CSS_PATH = "styles.tcss"

    def on_mount(self):
        self.push_screen(InterFace())


if __name__ == "__main__":
    app = Calculi()
    app.run()