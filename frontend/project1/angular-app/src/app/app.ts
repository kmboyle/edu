import { Component, signal } from '@angular/core';
import { RouterOutlet } from '@angular/router';
import { MaterialDemoComponent } from './material-demo.component';

@Component({
  selector: 'app-root',
  imports: [RouterOutlet, MaterialDemoComponent],
  templateUrl: './app.html',
  styleUrl: './app.scss'
})
export class App {
  protected readonly title = signal('angular-app');
}
