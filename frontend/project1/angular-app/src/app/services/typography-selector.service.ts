import { Injectable } from '@angular/core';
import { MatDialog } from '@angular/material/dialog';
import { TypographySelectorComponent } from '../dialogs/typography-selector.component';
import { Observable } from 'rxjs';

@Injectable({
  providedIn: 'root'
})
export class TypographySelectorService {
  constructor(private readonly dialog: MatDialog) { }

  openTypographySelector(): Observable<{ fontFamily: string } | undefined> {
    return this.dialog.open(TypographySelectorComponent, {
      width: '400px',
      height: '300px',
      disableClose: false
    }).afterClosed();
  }
}