import "./App.css";
import Node from "./components/Node/NodeComponent.js";
import Header from "./components/Header/HeaderComponent.js";

function App() {
  return (
    <>
      <Header></Header>
      <div className="App-container">
        <div>
          <Node />
        </div>
      </div>
    </>
  );
}

export default App;
