import './App.css'
import Task from './task'

function App() {

  return (
    <div className='App'>
      <h1>Hello</h1>
      <h3>Welcome to my To Do App</h3>
      <Task title='New title' description='new entry'/>
      <Task title=''/>
    </div>
  )
}

export default App
